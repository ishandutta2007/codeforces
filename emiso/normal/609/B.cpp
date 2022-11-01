#include <stdio.h>

int books[11];

int main() {
    int n,m,genre,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&genre);
        books[genre]++;
    }
    for(int i=1;i<=m;i++) {
        ans += (n-books[i])* books[i];
        n -= books[i];
    }
    printf("%d\n",ans);
    return 0;
}