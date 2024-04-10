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
#define st first
#define nd second
#define mp make_pair
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);++(i));
#define FORD(i,a,b) for(int (i)=(a);(i)>=(b);--(i));
#define RE(i,n) FOR((i),0,(n)-1)
#define FORE(i,w) for(typeof((w).begin()) (i)=(w).begin();(i)!=(w).end();++(i))
#define ALL(w) (w).begin(),(w).end()
#define IOS ios_base::sync_with_stdio(0)
const int inf=1e9+5;
bool qtesty = 0;
const int nax=1000123;

int t[nax];
map<int,int> mapa;
int ile;
vi res;
vi minpa,pluspa;

int pro()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i)scanf("%d",&t[i]);
    for(int i=1;i<=m;++i){
        int a;
        scanf("%d",&a);
        if(!mapa[a])ile++;
        mapa[a]++;
    }
    int memo=ile;
    for(int i=1;i<=min(p,n);++i){
        ile=memo;
        int j;
        for(j=i;j<=n && (j-i)/p<=m-1;j+=p){
            int pom=mapa[t[j]];
            if(pom==1)ile--;
            if(pom==0)ile++;
            mapa[t[j]]--;
            minpa.pb(t[j]);
        }
        j-=p;
        //printf("%d-%d %d\n",i,j,ile);
        if(!ile)res.pb(i);
        int pami=i;
        while(j+p<=n){
            int pom=mapa[t[i]];
            if(pom==-1)ile--;
            if(pom==0)ile++;
            mapa[t[i]]++;
            pluspa.pb(t[i]);
            i+=p;
            j+=p;
            pom=mapa[t[j]];
            if(pom==1)ile--;
            if(pom==0)ile++;
            mapa[t[j]]--;
            minpa.pb(t[j]);
            //printf("%d-%d %d\n",i,j,ile);
            if(ile==0)res.pb(i);
        }
        i=pami;
        int d=minpa.size();
        for(int i=0;i<d;++i)
            mapa[minpa[i]]++;
        d=pluspa.size();
        for(int i=0;i<d;++i)
            mapa[pluspa[i]]--;
        minpa.clear();pluspa.clear();
    }
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    int he=res.size();
    for(int i=0;i<he;++i)printf("%d ",res[i]);
        
    return 0;
}

int main()
{
    int z=1;
    if(qtesty)scanf("%d",&z);
    FOR(i,1,z){
        pro();
    }
    return 0;
}