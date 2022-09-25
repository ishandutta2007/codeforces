#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n;
int a,b,c;
char ch;
int nnot;
string fin;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        fin="";
        nnot=0;
        getchar();
        for (int x=0;x<n;x++){
            ch=getchar();
            if (ch=='R'){
                if (b) b--,fin+='P';
                else nnot++,fin+='?';
            }
            else if (ch=='P'){
                if (c) c--,fin+='S';
                else nnot++,fin+='?';
            }
            else{
                if (a) a--,fin+='R';
                else nnot++,fin+='?';
            }
        }
        if (nnot>(n>>1)){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for (int x=0;x<n;x++){
                if (fin[x]=='?'){
                    if (a) a--,putchar('R');
                    else if (b) b--, putchar('P');
                    else c--,putchar('S');
                }
                else putchar(fin[x]);
            }
            printf("\n");
        }
    }
}