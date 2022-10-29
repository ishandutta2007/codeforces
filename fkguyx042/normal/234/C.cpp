#include <cstdlib>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <map>  
using namespace std;  
int a[100010];  
struct node  
{  
    int da;  
    int xiao;  
}b[100010];  
int main()  
{  
    int n;  
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);  
    scanf("%d", &n);  
    for(int i = 0; i < n; i++)  
        scanf("%d", &a[i]);  
    int up = 0, down = 0, zero=0;  
    for(int i = 0; i < n; i++)  
    {  
        if(a[i]>0)  
            up++;  
        if(a[i]<0)  
            down++;  
        if(a[i]==0)  
            zero++;  
        b[i].da = up;  
        b[i].xiao = down;  
     //   printf("i=%d up=%d down=%d zero=%d\n", i, up, down,zero);  
    }  
    int m = 0x7ffffff;  
    for(int i = 0; i < n-1; i++)  
    {  
        int tmp = b[i].da+down-b[i].xiao;  
        if(m>tmp)  
            m = tmp;  
        //printf("i=%d up=%d down=%d tmp=%d m=%d\n", i, b[i].da, b[i].xiao,tmp,m);  
    }  
    printf("%d\n", m+zero);  
    return 0;  
}