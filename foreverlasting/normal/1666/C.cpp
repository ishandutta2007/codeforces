#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define gc getchar
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
const int N=1e6+10;
pii a[10];
int b[10];
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
int main(){
    for(int i=1;i<=3;++i) a[i].fr=rd(),a[i].sc=b[i]=rd();
    sort(a+1,a+3+1);sort(b+1,b+3+1);
    puts("3");
    printf("%d %d %d %d\n",a[2].fr,b[1],a[2].fr,b[3]);
    printf("%d %d %d %d\n",a[1].fr,a[1].sc,a[2].fr,a[1].sc);
    printf("%d %d %d %d\n",a[2].fr,a[3].sc,a[3].fr,a[3].sc);
    return 0;
}