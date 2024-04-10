#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 1005
void solve(){
    char c[10005];
    scanf("%s",c);
    int cnt[3]={0,0,0};
    for(int i = 0;c[i]!=0;i++)cnt[c[i]-'A']++;
    if(cnt[0]+cnt[2]==cnt[1])printf("YES\n");
    else printf("NO\n");
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*


9 12
.........
...###...
...#.#...
.#######.
...###...
...###...
.#..#....
.#######.
...###.#.
...###...
..##.##..
.........
.........
..#####..
..##.##..
..#...#..
..#...#..
..#...#..
..#####..
...#.#...
...#.#...
...#.#...
.###.###.
.........


7 6 2
0 1 1
1 2 0
2 3 0
3 4 0
4 5 0
5 6 1
l*a=r*b
a+b=1

1
6 16 4 11
..XXX..X.X.XXX..
.XXXX...XX..XX..
X....X.X.X.X..X.
X.X.X.X.XXXXX.XX
XX.XXX...X.X.XXX
.XX....XXXX..XXX
1 3
6 14
4 13
1 3
5 14
4 6
6 13
2 1
5 16
2 16
3 10
*/