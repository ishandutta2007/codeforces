#include <cstdio>
using namespace std;
int n,m;
char grid[70][70];
int main(){
    int TC;
    scanf("%d",&TC);
    
    while (TC--){
        scanf("%d%d",&n,&m);
        for (int x=0;x<n;x++){
            getchar();
            for (int y=0;y<m;y++){
                grid[x][y]=getchar();
            }
        }
        
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                if (grid[x][y]=='A') goto ok;
            }
        }
        printf("MORTAL\n");
        continue;
        ok:;
        
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                if (grid[x][y]=='P') goto lol;
            }
        }
        printf("0\n");
        continue;
        lol:;
        
        bool can=true;
        for (int x=0;x<n;x++){
            if (grid[x][0]=='P') can=false;
        }
        
        if (can){
            printf("1\n");
            continue;
        }
        
        can=true;
        for (int x=0;x<n;x++){
            if (grid[x][m-1]=='P') can=false;
        }
        
        if (can){
            printf("1\n");
            continue;
        }
        
        can=true;
        for (int x=0;x<m;x++){
            if (grid[0][x]=='P') can=false;
        }
        
        if (can){
            printf("1\n");
            continue;
        }
        
        can=true;
        for (int x=0;x<m;x++){
            if (grid[n-1][x]=='P') can=false;
        }
        
        if (can){
            printf("1\n");
            continue;
        }
        
        if (grid[0][0]=='A' || grid[0][m-1]=='A' || grid[n-1][0]=='A' || grid[n-1][m-1]=='A') {
            printf("2\n");
            continue;
        }
        
        for (int y=1;y<m-1;y++){
            
        can=true;
        for (int x=0;x<n;x++){
            if (grid[x][y]=='P') can=false;
        }
        
        if (can){
            printf("2\n");
            goto _end;
        }
        }
        
        for (int y=1;y<n-1;y++){
        can=true;
        for (int x=0;x<m;x++){
            if (grid[y][x]=='P') can=false;
        }
        
        if (can){
            printf("2\n");
            goto _end;
        }
        }
        
        for (int x=0;x<n;x++){
            if (grid[x][0]=='A' || grid[x][m-1]=='A') {
                printf("3\n");
                goto _end;
            }
        }
        
        for (int x=0;x<m;x++){
            if (grid[0][x]=='A' || grid[n-1][x]=='A') {
                printf("3\n");
                goto _end;
            }
        }
        
        printf("4\n");
        _end:;
    }
}