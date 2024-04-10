#include<cstdio>  
#include<algorithm>
#define MAXN 10000  
using namespace std;  
struct Node{  
    int v, t;  
} a[MAXN];  
int n,sum,maxb,cnt;
int b[MAXN], c[MAXN];  
int ans1[MAXN], ans2[MAXN];  
bool cmp(Node a, Node b) {    return a.v<b.v;  }  
int main() {    
    scanf("%d", &n);  
    for(int i=0; i<n; ++i) {  
        scanf("%d", &a[i].v);  
        a[i].t=i;  
    }  
    sort(a,a+n,cmp);  
    bool ok=false;  
    sum = 1; maxb = -1;  
    cnt = 0; b[0] = 1;  
    for(int i=0; i<n; ++i) {  
        if(a[i].v == a[i+1].v)  
            b[i+1] = b[i]+1;  
        else {  
            sum *= b[i];  
            if(sum > 2) {  
                ok = true;  
                sum = 0;  
            }  
            b[i+1]=1;  
        }  
        maxb=max(maxb,b[i]);  
    }  
    if(!ok)  
        puts("NO");  
    else {   
        puts("YES");  
        for(int i=0; i<n; ++i) {  
            printf("%d ", a[i].t+1);  
        }  
        puts("");  
        if(maxb == 2) {  
            bool flag = true;  
            for(int i=0; i<n; ++i) {  
                if(b[i] == 2 && flag) {  
                    ans1[i] = a[i-1].t;  
                    ans1[i-1] = a[i].t;  
                    flag = false;  
                }  
                else ans1[i] = a[i].t;  
            }  
  
            flag = false;  
            for(int i=0; i<n; ++i) {  
                if(b[i] > 1 && flag) {  
                    ans2[i] = a[i-1].t;  
                    ans2[i-1] = a[i].t;  
                    flag = false;  
                } else if(b[i] > 1) {  
                    flag = true;  
                    ans2[i] = a[i].t;  
                } else ans2[i] = a[i].t;  
            }  
  
            for(int i=0; i<n; ++i)  
                printf("%d ", ans1[i]+1);  
            puts("");  
            for(int i=0; i<n; ++i)  
                printf("%d ", ans2[i]+1);  
  
        } else {  
            bool flag  = true;  
            for(int i=0; i<n; ++i) {  
                if(b[i] > 2 && flag) {  
                    ans1[i] = a[i-1].t;  
                    ans1[i-1] = a[i-2].t;  
                    ans1[i-2] = a[i].t;  
                    ans2[i] = a[i-2].t;  
                    ans2[i-1] = a[i].t;  
                    ans2[i-2] = a[i-1].t;  
                    flag = false;  
                } else {  
                    ans1[i] = a[i].t;  
                    ans2[i] = a[i].t;  
                }  
            }  
            for(int i=0; i<n; ++i) {  
                printf("%d ", ans1[i]+1);  
            }  
            puts("");  
            for(int i=0; i<n; ++i)  
                printf("%d ", ans2[i]+1);  
        }  
    }  
    return 0;  
}