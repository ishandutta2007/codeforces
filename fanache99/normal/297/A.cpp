#include<cstdio>
using namespace std;
char a[1010],b[1010];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int i,a1=0,b1=0;
    scanf("%s%s",&a,&b);
    i=0;
    while(a[i]=='0'||a[i]=='1'){
        a1=a1+a[i]-'0';
        i++;
    }
    i=0;
    while(b[i]=='0'||b[i]=='1'){
        b1=b1+b[i]-'0';
        i++;
    }
    if(a1+a1%2>=b1)
        printf("YES");
    else
        printf("NO");
    return 0;
}