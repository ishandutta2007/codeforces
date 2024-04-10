#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){
    char c[1005];
    scanf("%s",c);
    int n=strlen(c);
    for(int i = 0;i<n;i++){
        char a=c[i],b=c[n-i-1];
        if(a=='A'&&b=='A');
        else if(a=='b'&&b=='d');
        else if(a=='d'&&b=='b');
        else if(a=='H'&&b=='H');
        else if(a=='I'&&b=='I');
        else if(a=='M'&&b=='M');
        else if(a=='O'&&b=='O');
        else if(a=='o'&&b=='o');
        else if(a=='p'&&b=='q');
        else if(a=='q'&&b=='p');
        else if(a=='T'&&b=='T');
        else if(a=='U'&&b=='U');
        else if(a=='V'&&b=='V');
        else if(a=='v'&&b=='v');
        else if(a=='W'&&b=='W');
        else if(a=='w'&&b=='w');
        else if(a=='X'&&b=='X');
        else if(a=='x'&&b=='x');
        else if(a=='Y'&&b=='Y');
        else{
           // printf("%c %c %d\n",a,b,i);
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/