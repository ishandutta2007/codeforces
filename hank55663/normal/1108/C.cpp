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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
#define MAXN 605
int main(){
    int n;
    char c[200005];
    scanf("%d %s",&n,c);
    vector<char> v;
    v.pb('R');
    v.pb('G');
    v.pb('B');
    sort(v.begin(),v.end());
    int Min=1e9;
    string ans;
    do{
        string str;
        int cnt=0;
        for(int i=0;i<n;i++){
            str+=v[i%3];
            if(v[i%3]!=c[i])
                cnt++;
        }
        if(cnt<Min){
            Min=cnt;
            ans=str;
        }
    }while(next_permutation(v.begin(),v.end()));
    printf("%d\n",Min);
    cout<<ans<<endl;
}