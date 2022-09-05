#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define x first
#define y second
#define mp make_pair
#define RE(i,n) for(int i=0;i<(n);++i)
#define RI(i,n) for(int i=1;i<=(n);++i)
#define IOS ios_base::sync_with_stdio(0)
const int inf=1e9+5;
const int nax=505;

int H,W,k;
int t[nax][nax],dobre[nax][nax];
char sl[nax];

int F(int a, int b)
{
    if(!k)return 0;
    dobre[a][b]=1;
    k--;
    for(int i=a-1;i<=a+1;++i)for(int j=b-1;j<=b+1;++j)
        if(abs(a-i)+abs(b-j)==1)
            if(!dobre[i][j])if(t[i][j])F(i,j);
    return 0;
}

int pro()
{
    scanf("%d%d%d",&H,&W,&k);
    k=-k;
    RI(i,H){
        scanf("%s",sl);
        RI(j,W)if(sl[j-1]=='.'){
            t[i][j]=1;
            k++;
        }
    }
    RI(i,H)RI(j,W)if(t[i][j]){
        F(i,j);
        i=H;j=W;
    }
    RI(i,H){
        RI(j,W){
            if(!t[i][j])printf("#");
            else if(!dobre[i][j])printf("X");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    int z=1;
    //scanf("%d",&z);
    RI(_,z)pro();
    return 0;
}