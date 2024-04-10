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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[105];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int ans=0;
    for(int j = 0;j<30;j++){
        int ok=1;
        for(int i = 0;i<n;i++){
            if(a[i]&(1<<j));
            else ok=0;
        }
        if(ok)ans+=(1<<j);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
62 3 2 6 5 10
1011110011
0101100000
1011000111
1000111010
1111010010
1010010001
1101010111
0101010010
1000001101
0000100001

10011
00000
00111
11010
10010

11 3 2 8 10 10
1001000000
0100101010
1100110001
1101001011
1111101000
0111100110
1011111100
0111001101
1111001000
0101000110



0010
0011
1001
0111
84 3 2 1 3 3
*/