#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define koks first
#define cena second
#define mp make_pair
#define RE(i,n) for(int i=0;i<(n);++i)
#define RI(i,n) for(int i=1;i<=(n);++i)
#define IOS ios_base::sync_with_stdio(0)
const int inf=1e9+5;
const int nax=1000123;

int n,m,S,hard[nax],memo[nax],start[nax],wynik[nax];
pair<int, pii > t[nax];
vi res;
struct cmp{
    bool operator()(int a, int b){
        if(t[a].cena.cena!=t[b].cena.cena)return t[a].cena.cena<t[b].cena.cena;
        return a<b;
    }
};
set<int,cmp> s;
map<int,vi > M;

bool F(int days)
{
    int hajs=0;
    res.clear();
    s.clear();
    int on=0,zad=0;
    while(1){
        while(on<n && t[on].koks>=hard[zad])
            s.insert(on++);
        if(s.empty()){//printf("raz\n");
        return 0;}
        int pom=*s.begin();
        hajs+=t[pom].cena.cena;
        //printf("\n >%d %d\n",hajs,S);
        if(hajs>S){//printf("dwa\n");
        return 0;}
        res.pb(pom);
        s.erase(s.begin());
        zad+=days;
        if(zad>=m)return 1;
    }
    return 0;
}

bool Fost(int days)
{
    int hajs=0;
    res.clear();
    s.clear();
    int on=0,zad=0;
    while(1){
        while(on<n && t[on].koks>=hard[zad])
            s.insert(on++);
        if(s.empty())return 0;
        int pom=*s.begin();
        hajs+=t[pom].cena.cena;
        if(hajs>S)return 0;
        res.pb(pom);
        s.erase(s.begin());
        //printf("\n%d-%d\n",zad,min(m,zad+days));
        for(int i=zad;i<min(m,zad+days);++i){
            //printf("%d\n",M[hard[i]][     M[hard[i]].size()-1    ]);
            wynik[M[hard[i]][ M[hard[i]].size()-1   ]]=t[pom].cena.koks+1;
            M[hard[i]].pop_back();
        }
        start[pom]=hard[zad]; // here
        zad+=days;
        if(zad>=m)return 1;
    }
    return 0;
}   

int pro()
{
    int musisz=inf;
    scanf("%d%d%d",&n,&m,&S);
    int najtrudniejsze=0,najlepszy=0;
    RE(i,m){
        scanf("%d",&hard[i]);
        M[hard[i]].pb(i);
        memo[i]=hard[i];
        najtrudniejsze=max(najtrudniejsze,hard[i]);
    }
    sort(hard,hard+m);
    reverse(hard,hard+m);
    RE(i,n){
        scanf("%d",&t[i].koks);
        t[i].cena.koks=i;
        najlepszy=max(najlepszy,t[i].koks);
    }
    RE(i,n){
        scanf("%d",&t[i].cena.cena);
        if(t[i].koks>=najtrudniejsze) musisz=min(musisz,t[i].cena.cena);
    }
    if(najlepszy<najtrudniejsze || musisz>S)return printf("NO");
    printf("YES\n");
    sort(t,t+n);
    reverse(t,t+n);
    int low=1,high=m;
    while(low!=high){
        int med=(low+high)/2;
        //printf("%d ",med);
        if(F(med)){
            high=med;
            //printf("tak\n");
        }
        else{
            low=med+1;
            //printf("nie\n");
        }
    }
    //printf("%d\n",low);
    Fost(low);
    RE(i,m)printf("%d ",wynik[i]);
    return 0;
}

int main()
{
    int z=1;
    //scanf("%d",&z);
    RI(_,z)pro();
    return 0;
}