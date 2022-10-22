#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

char ans[100005];

int main()
{
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    if(b-1-(a*10-1)%b < 0 || b-1-(a*10-1)%b >= 10){
        printf("-1");
        return 0;
    }
    printf("%d%d", a, b-1-(a*10-1)%b);
    for(int i=0; i < n-1; ++i)
        printf("0");
    return 0;
}