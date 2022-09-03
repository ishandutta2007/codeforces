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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
bool solve(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    int ti;
    int Max;
    if(a<b){
        ti=b-2;
        Max=b-a-1;
    }
    else if(a>b){
        ti=n-b-1;
        Max=a-b-1;
    }
    int s[200005];
    for(int i = 0;i<m;i++){
        scanf("%d",&s[i]);
    }
    sort(s,s+m);
    reverse(s,s+m);
    int ans=0;
    for(int i=0;i<m;i++){
        if(ti>=s[i]&&Max){
            ans++;
            ti--;
            Max--;
        }
        if(!Max)break;
    }
    printf("%d\n",ans);
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/