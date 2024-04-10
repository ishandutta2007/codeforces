#include<bits/stdc++.h>  
#define LL long long   
#define rep(i,a,b) for(int i=a;i<=b;i++)  
#define dep(i,a,b) for(int i=a;i>=b;i--)  
using namespace std;  
const int maxn=3005;  
char c[]="aeiou";  
char s[maxn];  
   
inline bool check(char ch)  
{  
    rep(i,0,4)if(ch==c[i])return 0;  
    return 1;  
}  
int main()  
{  
    scanf("%s",s);  
    int n=strlen(s),lst=-1;  
    rep(i,0,n-1){  
        putchar(s[i]);  
        if(i!=n-1&&lst<=i-2&&check(s[i])&&check(s[i-1])&&check(s[i+1])&&(s[i]!=s[i-1]||s[i]!=s[i+1]||s[i-1]!=s[i+1]))  
        {  
            putchar(' ');  
            lst=i;  
        }  
    }  
    cout<<" ";  
    return 0;  
}