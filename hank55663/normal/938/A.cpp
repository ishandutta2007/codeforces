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
bool vowels(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
    return true;
    return false;
}
int main(){
	int n;
    scanf("%d",&n);
    char c[105];
    scanf("%s",c);
    int last=0;
    for(int i=0;c[i]!=0;i++){
        if(last&&vowels(c[i]))continue;
        else{
            printf("%c",c[i]);
            if(vowels(c[i]))last=1;
            else last=0;
        }
    }
}