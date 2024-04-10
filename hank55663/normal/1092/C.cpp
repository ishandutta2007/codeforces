
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
int main(){
    int n;
    scanf("%d",&n);
    string s[200];
    vector<string> ans;
    for(int i=0;i<2*n-2;i++){
        cin>>s[i];
        if(s[i].size()==n-1){
            ans.pb(s[i]);
        }
    }
    for(int tt=0;tt<2;tt++){    
        string target=ans[0]+ans[1][n-2];
        //cout<<target<<endl;
        int front[105],end[105];
        MEM(front);
        MEM(end);
        vector<char> pri;
        int ok=1;
        for(int j=0;j<2*n-2;j++){
            int len=s[j].size();
            if(s[j]==target.substr(0,len)&&!front[len]){
                pri.pb('P');
                front[len]=1;
            }
            else if(s[j]==target.substr(n-len,len)&&!end[len]){
                pri.pb('S');
                end[len]=1;
            }
            else{
                ok=0;
            }
        }
        if(ok){
            for(auto it:pri)
            printf("%c",it);
            printf("\n");
            return 0;
        }
        swap(ans[0],ans[1]);
    }
}