#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
using namespace std;
string ans;
int loc[505];
int now[505];
string res;
int k;
void dfs(int i,int n){
    if(i==n){
        ans=min(ans,res);
        return ;
    }
    res[loc[i]]=(res[loc[i]]-'a'-1+k)%k+'a';
    dfs(i+1,n);
    res[loc[i]]=(res[loc[i]]-'a'+1)%k+'a';
    dfs(i+1,n);
    res[loc[i]]=(res[loc[i]]-'a'+1)%k+'a';
    dfs(i+1,n);
    res[loc[i]]=(res[loc[i]]-'a'-1+k)%k+'a';
    if(loc[i]!=0){
        //loc[il-1 loc[i]
        swap(res[loc[i]-1],res[loc[i]]);
        swap(now[loc[i]-1],now[loc[i]]);
        swap(loc[now[loc[i]]],loc[now[loc[i]-1]]);
        dfs(i+1,n);
        swap(res[loc[i]+1],res[loc[i]]);
        swap(now[loc[i]+1],now[loc[i]]);
        swap(loc[now[loc[i]]],loc[now[loc[i]+1]]);
    }
    if(loc[i]!=n-1){
        swap(res[loc[i]+1],res[loc[i]]);
        swap(now[loc[i]+1],now[loc[i]]);
        swap(loc[now[loc[i]]],loc[now[loc[i]+1]]);
        dfs(i+1,n);
        swap(res[loc[i]-1],res[loc[i]]);
        swap(now[loc[i]-1],now[loc[i]]);
        swap(loc[now[loc[i]]],loc[now[loc[i]-1]]);
    }
}
void solve(){
    int n=8;
    k=5;
    scanf("%d %d",&n,&k);
    char c[505];
    for(int i = 0;i<n;i++)c[i]=rand()%k+'a';
    c[n]=0;
   // printf("%s\n",c);
   scanf("%s",c);
    for(int i = 0;c[i]!=0;i++)loc[i]=i,now[i]=i;
    ans=res=string(c);
  //  dfs(0,n);
    for(int i = 0;i<n;i++){
        if(i!=0&&i!=n-1&&res[i+1]<res[i-1]&&res[i+1]<res[i]){
            swap(res[i+1],res[i]);
            swap(res[i],res[i-1]);
            i++;
        }
        else if(i!=0&&res[i-1]>res[i]){
            swap(res[i-1],res[i]);
        }
        else if(res[i+1]=='a'+k -1&& res[i]!='a'&&res[i]!='b'&&res[i]!='a'+k-1){
            res[i+1]='a';
            swap(res[i],res[i+1]);
            i++;
        }
        else if(res[i]=='a'+k-1||res[i]=='b'||((i==n-1||res[i]<=res[i+1])&&(i>=n-2||res[i]<=res[i+2]+1))){
          //  printf("%d\n",i);
            if(res[i]=='a');
            else if(res[i]=='a'+k-1)res[i]='a';
            else res[i]--;
        }
       // else 
        else if(i<n-2&&res[i+2]<res[i]&&res[i+2]<res[i+1]-1){
            if(res[i]=='a');
            else if(res[i]=='a'+k-1)res[i]='a';
            else res[i]--;
            swap(res[i+1],res[i+2]);
            swap(res[i],res[i+1]);
            i+=2;
        }
        else{
            if(res[i+1]=='a'){
                res[i]--;
            }
            else{
                res[i+1]--;
            }
            swap(res[i],res[i+1]);
            i++;
        }
       //  cout<<res<<" "<<i<<endl;
    }
   printf("%s\n",res.c_str());
   // cout<<ans<<endl;
   // cout<<res<<endl;
   // assert(ans==res);
   // printf("%s\n",c);

}  
int main(){
    int t=1;
    scanf("%d",&t);
    //int n;
    while(t--){
        solve();
    }
}
/*

8 4
ccbdbadc
*/