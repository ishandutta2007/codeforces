#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int m;
    scanf("%d",&m);
    int s[1005];
    for(int i = 0;i<m;i++) 
        scanf("%d",&s[i]);
    for(int i = 0;i<m;i++){
        if(s[i]%s[0]!=0){
            printf("-1\n");
            return 0;
        }
    }
    vector<int> v;
    v.pb(s[0]);
    for(int i = 1;i<m;i++){
        v.pb(s[i]);
        v.pb(s[0]);
    }
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/