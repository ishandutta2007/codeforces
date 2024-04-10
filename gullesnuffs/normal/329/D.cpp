#include <stdio.h>
typedef long long Int;

using namespace std;

int n;
char ans[105][105];
int test[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char signs[4]={'v', '>', '^', '<'};

int main(){
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            ans[i][j]='.';
    int m=1;
    for(int i=0; i < n; i += 2){
        for(int j=0; j < n/2; ++j)
            ans[i][j]='>';
        for(int j=0; j < n-1; j += 2)
            ans[i][j]='>';
        ans[i][n-1]='v';
        for(int j=0; j < n/2; ++j)
            ans[i+1][n-1-j]='<';
        for(int j=0; j < n-1; j += 2)
            ans[i+1][n-1-j]='<';
        ans[i+1][0]='^';
    }
    for(int i=0; i < n; ++i){
        ans[i][n]=0;
        printf("%s\n", ans[i]);
    }
    printf("%d %d\n", 1, n);
    return 0;
}