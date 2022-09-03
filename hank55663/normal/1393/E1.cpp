#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<int> dp[100005];
string s[100005];
int same,same2[1000005],same3[1000005],same4[1000005];
int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
      //  int x=rand()%3+1;
      //  for(int i = 0;i<x;i++)c[i]=rand()%2+'a';
     //   c[x]=0;
        s[i]=string(c);
    }
    for(int i = 0;i<s[0].size();i++){
        dp[0].pb(1);
    }
    dp[0].pb(1);
    for(int i = 1;i<n;i++){
      //  int same;
        for(same = 0;same!=max(s[i].size(),s[i-1].size())&&s[i][same]==s[i-1][same];same++){
        }
     //   int same2[1000005];
        int now=0;
        for(int j = 0;j<=s[i-1].size();j++){
            while((j+now<s[i-1].size()&&j+1+now<s[i].size())&&s[i-1][j+now]==s[i][j+1+now])now++;
            same2[j]=j+now;
            now--;
            if(now<0)now=0;
        }
      //  int same3[1000005];
        now=0;
        for(int j = 0;j<=s[i].size();j++){
            while((j+now<s[i].size()&&j+1+now<s[i-1].size())&&s[i][j+now]==s[i-1][j+1+now])now++;
            same3[j]=j+now;
            now--;
            if(now<0)now=0;
        }
       // int same4[1000005];
        now=0;
        for(int j = 0;j<=s[i].size()||j<=s[i-1].size();j++){
            
            while((j+now<s[i].size()&&j+now<s[i-1].size())&&s[i][j+now]==s[i-1][j+now])now++;
            same4[j]=j+now;
            now--;
            if(now<0)now=0;
        }
        //if(s[i].size()==s[i-1].size())same4[s[i].size()]=s[i].size();
        deque<int> q1,q2;
        q1.pb(s[i-1].size());
        int last;
        for(int j = s[i-1].size()-1;j>=0;j--){
            if(s[i-1][j]>s[i-1][j+1]){
                q1.push_front(j);
                last=1;
            }
            else if(s[i-1][j]<s[i-1][j+1]){
                q1.push_back(j);
                last=0;
            }
            else{
                if(last)q1.push_front(j);
                else q1.push_back(j);
            }
        }
        q2.pb(s[i].size());
        for(int j = s[i].size()-1;j>=0;j--){
            if(s[i][j]>s[i][j+1]){
                q2.push_front(j);
                last=1;
            }
            else if(s[i][j]<s[i][j+1]){
                q2.push_back(j);
                last=0;
            }
            else{
                if(last)q2.push_front(j);
                else q2.push_back(j);
            }
        }
        LL sum=0;
        dp[i].resize(s[i].size()+1);
        while(!q1.empty()||!q2.empty()){
            if(q1.empty()){
                dp[i][q2.front()]=sum;
              //   printf("(%d,%d)",i,q2.front());
                q2.pop_front();
               
            }
            else if(q2.empty()){
                break;
            }
            else{
                int a=q1.front(),b=q2.front();
                int big=0;
               // printf("%d %d\n",a,b);
                if(min(a,b)<=same){
                 //   printf("?\n");
                    if(a>b){
                        if(same2[b]<a){
                            char x,y;
                            if(same2[b]>=s[i-1].size())x=0;
                            else x=s[i-1][same2[b]];
                            if(same2[b]+1>=s[i].size())y=0;
                            else y=s[i][same2[b]+1];
                            if(x<=y){
                                big=1;
                            }
                        }
                        else{
                            char x,y;
                            if(same4[a+1]>=s[i-1].size())x=0;
                            else x=s[i-1][same4[a+1]];
                            if(same4[a+1]>=s[i].size())y=0;
                            else y=s[i][same4[a+1]];
                            if(x<=y){
                                big=1;
                            }
                        }
                    }
                    else if(a==b){
                        char x,y;
                        if(same4[a+1]>=s[i-1].size())x=0;
                        else x=s[i-1][same4[a+1]];
                        if(same4[a+1]>=s[i].size())y=0;
                        else y=s[i][same4[a+1]];
                        if(x<=y){
                            big=1;
                        }
                    }
                    else{
                        if(same3[a]<b){
                          //  printf("?? %d\n",same4[a]);
//assert(same3[a]<=s[i-1].size());
  //                          assert(same3[a]+1<=s[i].size());
                            char x,y;
                            if(same3[a]+1>=s[i-1].size())x=0;
                            else x=s[i-1][same3[a]+1];
                            if(same3[a]>=s[i].size())y=0;
                            else y=s[i][same3[a]];
                            if(x<=y){
                                big=1;
                            }
                           // if(c<=s[i][same3[a]])big=1;
                        }
                        else{
                           char x,y;
                            if(same4[b+1]>=s[i-1].size())x=0;
                            else x=s[i-1][same4[b+1]];
                            if(same4[b+1]>=s[i].size())y=0;
                            else y=s[i][same4[b+1]];
                            if(x<=y){
                                big=1;
                            }
                        }
                    }
                    if(big){
                        sum+=dp[i-1][a];
                        sum%=mod;
                        q1.pop_front();
                     //   printf("(%d,%d)",i-1,a);
                    }
                    else{
                        dp[i][b]=sum;
                      //  printf("(%d,%d)",i,b);
                        q2.pop_front();
                    }
                }
                else{
                    if(s[i][same]>=s[i-1][same]){
                        sum+=dp[i-1][a];
                        sum%=mod;
                     //    printf("(%d,%d)",i-1,a);
                        q1.pop_front();
                    }
                    else{
                        dp[i][b]=sum;
                     //   printf("(%d,%d)",i,b);
                        q2.pop_front();
                    }
                }
            }
        }
      /*  printf("\n");
        for(auto it:dp[i]){
            printf("%d ",it);
        }
        printf("\n");*/
    }
    LL ans=0;
    for(auto it:dp[n-1]){
        ans+=it;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/