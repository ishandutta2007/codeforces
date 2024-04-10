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
int main(){
    char c[5005];
    scanf("%s",c);
    int same=1;
    for(int i=1;c[i]!=0;i++){
        if(c[i]!=c[i-1])same=0;
    }
    if(same){
        printf("Impossible\n");
        return 0;
    }
    else{
        if(strlen(c)%2==0){
        }
        else
        {
            int mid=strlen(c)/2;
            int same=1;
            for(int i=1;i<mid;i++){
                if(c[i]!=c[i-1])same=0;
            }
            if(same){
                printf("Impossible\n");
                return 0;
            }
        }
    }
    string s(c);
    for(int i=1;i<s.size();i++){
        string temp=s.substr(i,s.size()-i)+s.substr(0,i);
        string temp1=temp;
        reverse(temp1.begin(),temp1.end());
        if(temp!=s&&temp==temp1){
            printf("1\n");
            return 0;
        }
    }
    printf("2\n");
}
/*

i f f x f l b
*/