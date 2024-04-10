#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[123];
int n;
int main() {
    scanf("%d%s",&n,s+1);
    int cnt=0,cc=0;
    int i;
    for(i=1;i<=n;i++) {
        if(s[i]=='8') cnt++;
    }
    printf("%d\n",min(cnt,n/11));
}