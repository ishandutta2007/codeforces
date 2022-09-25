#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
char grid[105][105];
int chick[105][105];
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d%d",&n,&m,&k);

        int rice=0;
        for (int x=0;x<n;x++){
            getchar();
            for (int y=0;y<m;y++){
                grid[x][y]=getchar();
                if (grid[x][y]=='R') rice++;
            }
        }

        int goal=rice/k;
        int over=rice-goal*k;
        if (over) goal++;

        int X=0, Y=0;

        int chicken=0;
        int curr=0;
        while (Y!=n){
            //printf("%d %d %d\n",X,Y,chicken);
            chick[Y][X]=chicken;
            if (grid[Y][X]=='R') curr++;
            if (curr==goal){
                over--;
                curr=0;
                if (over==0) goal--;
                chicken++;
            }
            if (Y%2==0){
                if (X==m-1) Y++;
                else X++;
            }
            else{
                if (X==0) Y++;
                else X--;
            }
        }

        k--;
        int tp;
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                tp=min(chick[x][y],k);
                if (tp<26){
                    printf("%c",'a'+tp);
                }
                else if (tp<52){
                    tp-=26;
                    printf("%c",'A'+tp);
                }
                else{
                    tp-=52;
                    printf("%c",'0'+tp);
                }
            }
            printf("\n");
        }
    }
}