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
#define N 100000
#define rank Rank
bool solve(){
    char s[55],t[55];
    scanf("%s %s",s,t);
    int n=strlen(s),m=strlen(t);
    int lcd=n*m/__gcd(n,m);
    string s1(s),t1(t);
    for(int i = 1;i<lcd/n;i++)s1+=string(s);
    for(int i = 1;i<lcd/m;i++)t1+=string(t);
    if(s1==t1)printf("%s\n",s1.c_str());
    else printf("-1\n");
}
int main(){
    int t=1;//00000;
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