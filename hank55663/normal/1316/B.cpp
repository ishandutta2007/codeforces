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
#define pi acosl(-1)
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
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        string ans=s;
        int res=1;
        for(int i = 1;i<=n;i++){
            string l=s.substr(0,i-1),r=s.substr(i-1,n-i+1);
            if((n-i)%2==0)reverse(l.begin(),l.end());
            if(ans>r+l){
                ans=r+l;
                res=i;
            }
            /*
            ans=min(ans,r+l);
            if(ans)*/
        }
        
        cout<<ans<<endl;
        cout<<res<<endl;
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/