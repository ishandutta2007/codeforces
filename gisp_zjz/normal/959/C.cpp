#include<bits/stdc++.h>

using namespace std;
int n;

int main()
{
    scanf("%d",&n);
    if (n<6) cout << -1 << endl;
    else {
        printf("1 2\n1 3\n1 4\n");
        for (int i=5;i<=n;i++) printf("2 %d\n",i);
    }
    for (int i=1;i<n;i++) printf("%d %d\n",i,i+1);
    return 0;
}