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
    char c[105],c1[105];
    scanf("%s %s",c,c1);
    int x=1,y=0;
    string s;
    s+=c[0];
    while(y==0){
        if((c[x]<c1[y]&&c[x]!=0))
            s+=c[x++];
        else
            s+=c1[y++];
    }
    cout<<s<<endl;
}