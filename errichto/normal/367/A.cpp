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
#define RE(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORE(i,w) for(typeof((w).begin()) (i)=(w).begin();(i)!=(w).end();++(i))
#define ALL(w) (w).begin(),(w).end()
#define IOS ios_base::sync_with_stdio(0)
const int inf=1e9+5;
bool qtesty = 0;
const int nax=1000123;

char s[nax];
int res[3];
int t[nax][3];

int pro()
{
    scanf("%s",s);
    int n=strlen(s);
    t[0][s[0]-'x']++;
    for(int i=1;i<n;++i){
        //RE(j,3)t[i][j]=t[i-1][j];
        for(int j=0;j<3;++j)t[i][j]=t[i-1][j];
        
        t[i][s[i]-'x']++;
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        int d=b-a+1;
        if(d<3)printf("YES\n");
        else{
            for(int j=0;j<3;++j)res[j]=t[b-1][j];
            if(a>1)for(int j=0;j<3;++j)res[j]-=t[a-2][j];
            int ma=0,mi=inf;
            for(int j=0;j<3;++j){
                ma=max(ma,res[j]);
                mi=min(mi,res[j]);
            }
            if(ma-mi>1)printf("NO\n");
            else printf("YES\n");
        }
    }
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