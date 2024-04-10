/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int cnt[500005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    string s,s1;
    cin>>s>>s1;
    if(k==1||s==s1){
        printf("%d\n",n);
    }
    else{
        k-=2;
        LL ans=n*2;
        int ok=0;
        MEM(cnt);
        for(int i=0;i<n;i++){
            if(ok){
                if(s[i]=='a'){
                    cnt[n-i]++;
                ///    printf("%d\n",n-i-1);
                }
                if(s1[i]=='b'){
                    cnt[n-i]++;
                 //   printf("%d\n",n-i-1);
                }
            }
            if(!ok&&s[i]!=s1[i]){
                ans-=i;
                ok=1;
            }
        }
      //  printf("%d\n",ans);
        LL tot=0,add=0;
        for(int i=n;i>=0;i--){
            ans+=min(tot+cnt[i],(LL)k)*i;
            //tot+=cnt[i];
            //printf("%d %d\n",tot);
            k-=tot+cnt[i];
            tot+=tot+cnt[i];
            if(k<=0)
            break;
        }
        printf("%lld\n",ans);
    }
}