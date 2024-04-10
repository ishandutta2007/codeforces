 #pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
#define Line pll
typedef long long LL;
int Isprime[5500];
int main(){
    fill(Isprime,Isprime+5500,1);
    for(int i=2;i<5500;i++){
        if(Isprime[i]){
            for(int j=i*2;j<5500;j+=i)
                Isprime[j]=0;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s[5300];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int k=n;
    vector<int> ans;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])cnt++;
        else ans.pb(cnt),cnt=1;
    }
    ans.pb(cnt);
   // printf("?\n");
    for(int i=0;i<k;i++){
       // printf("%d\n",i);
        vector<int> v;
        for(int j=n/4-1;j>=0;j--){
            int num;
            if(s[i][j]<='9'&&s[i][j]>='0'){
                num=s[i][j]-'0';
            }
            else{
                num=s[i][j]-'A'+10;
            }
            for(int kk=0;kk<4;kk++){
                v.pb(num&1);
                num>>=1;
            }
        }
        int cnt=1;
        for(int j=1;j<n;j++){
            if(v[j]==v[j-1])cnt++;
            else ans.pb(cnt),cnt=1;
        }
        ans.pb(cnt);
    }
    int res=ans[0];
    for(auto it:ans){
      //  printf("%d\n",it);
        res=__gcd(res,it);
    }
    cout<<res<<endl;
}