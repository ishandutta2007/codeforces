#include <cstdio>
int a[105]; int n;char s[105];

int main() {
    scanf("%d", &n);
    scanf("%s", &s);
    for (int i=1;i<=n;++i){
        a[i]=s[i-1]-'0';// printf("%d", a[i]);
    } 
    for (int i=0;i<=1000;++i) {
        int t1=0, t2=0;
        for (int j=1;j<=n;++j) {
            t1+=a[j];
            if (t1==i) {
                t2++; t1=0;
            }if (t1>i) {t2=0;break;}
        }if (t1!=0||t2<2) continue;
        printf("YES");
        return 0;
    }printf("NO");
    return 0;
}