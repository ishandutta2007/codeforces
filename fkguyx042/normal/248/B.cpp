#include <stdio.h>  
  
void solve(int n){  
    char a[7][3]={"05", "08", "17", "02", "20", "11"};  
    if (n <= 3) {  
        printf("%d\n", n == 3 ? 210 : -1);  
        return ;  
    }  
    int tmp = (n - 4) % 6;  
    printf("1");  
    for (int i = 0; i < n - 4; ++ i)  
        printf("0");  
    printf("%s0\n", a[tmp]);  
}  
  
int main(){  
    int n;  
    while (~scanf("%d", &n)){  
        solve(n);  
    }  
    return 0;  
}