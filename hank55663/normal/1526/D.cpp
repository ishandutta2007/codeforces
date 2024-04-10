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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    vector<int> v[26];
   // int n;
   // scanf("%d",&n);
    char c[100005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        v[c[i]-'A'].pb(i);
    }
    int n=strlen(c);
    string str="ANTO";
    sort(str.begin(),str.end());
    LL ans=-1;
    string anss;
    do{
        LL sum=0;
        for(int i = 0;i<4;i++){
            for(int j = i+1;j<4;j++){
                int cnt[100005];
                fill(cnt,cnt+n,0);
                for(auto it:v[str[j]-'A'])cnt[it]++;//printf("%d ",it);
                //printf("\n");
                for(int k=1;k<n;k++){
                    cnt[k]+=cnt[k-1];
                }   
                for(auto it:v[str[i]-'A'])sum+=cnt[it];//printf("%d ",it);
                //printf("\n");
            }
        }
       // printf("%lld\n",sum);
       // printf("%s\n",str.c_str());
        if(sum>ans){
            ans=max(ans,sum);
            anss=str;
        }
    }while(next_permutation(str.begin(),str.end()));
   // printf("%s\n",anss.c_str());
    for(auto it:anss){
        for(auto it2:v[it-'A']){
            printf("%c",it);
        }
    }
    printf("\n");
  //  printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/