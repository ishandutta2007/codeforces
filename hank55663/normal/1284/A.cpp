#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){ 
    int n,m;
    scanf("%d %d",&n,&m);
    string s[20],t[20];
    for(int i = 0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++)cin>>t[i];
    int q;
    scanf("%d",&q);
    while(q--){
        int y;
        scanf("%d",&y);
        y--;
        cout<<s[y%n]<<t[y%m]<<endl;
    }
}