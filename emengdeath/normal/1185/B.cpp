#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
struct node{
    char s[1000100];
    int a[1000100];
    int n;
    void work() {
        n = strlen(s);
        a[0] = 1;
        a[1] = 1;
        for (int i = 1; i <= n ; i ++) {
            if (s[i] != s[a[0] - 1]){
                s[a[0]] = s[i];
                a[0] ++;
                a[a[0]] = 0;
            }
            a[a[0]] ++;
        }
    }
}A, B;
int main()
{
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s", A.s);
        scanf("%s", B.s);
        A.work();
        B.work();
        if (A.a[0] != B.a[0]) printf("NO\n");
        else{
            bool sig=  1;
            for (int i = 1; i <= A.a[0] && sig; i ++)
                if (A.a[i] > B.a[i] || A.s[i - 1] != B.s[i - 1]) {
                    sig = 0;
                }
            if (!sig) printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}