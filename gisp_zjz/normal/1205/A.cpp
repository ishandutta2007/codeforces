#include<bits/stdc++.h>
using namespace std;
int a[555555];
int n;
int main(){
    cin >> n;
    if (n%2==0){puts("NO");return 0;}
    puts("YES");
    for (int i=0;i<n;i++) printf("%d ",i*2+(i&1)+1);
    for (int i=0;i<n;i++) printf("%d ",i*2+((i+1)&1)+1);
    puts("");
    return 0;
}