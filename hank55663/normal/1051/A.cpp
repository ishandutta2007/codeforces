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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int upper=0,lower=0,digit=0;
        char c[105];
        scanf("%s",c);
        for(int i=0;c[i]!=0;i++){
            if(c[i]>='A'&&c[i]<='Z')
            upper++;
            else if(c[i]>='a'&&c[i]<='z')
            lower++;
            else 
            digit++;
        }
        string s;
        if(!upper)s+='A';
        if(!lower)s+='a';
        if(!digit)s+='1';
        int ok=1;
        for(int i=0;i<s.size();i++){
            if(c[i]>='A'&&c[i]<='Z'){
                if(--upper==0)ok=0;
            }
            else if(c[i]>='a'&&c[i]<='z'){
                if(--lower==0)ok=0;
            }
            else{ 
                if(--digit==0)ok=0;
            }
        }
        if(ok)
        {
            cout<<s;
            printf("%s\n",c+s.size());
        }
        else{
            for(int i=0;c[i+s.size()]!=0;i++)
            printf("%c",c[i]);
            cout<<s<<endl;
        }
    }
    return 0;
}