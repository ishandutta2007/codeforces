#include<bits/stdc++.h>
using namespace std;
int Q;
long long a[60];
long long u,mod,v;
int sig,level;
int getlevel(long long s){
    int i=0;
    while (s!=1)i++,s/=2;
    return i;
}

void get(int &x)
{
    char c = getchar(); x = 0;
    int sig=1;
    while(c < '0' || c > '9'){
        if (c=='-')sig=-1;
        c = getchar();
    }
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
    x*=sig;
}
void get(long long &x)
{
    char c = getchar(); x = 0;
    int sig=1;
    while(c < '0' || c > '9'){
        if (c=='-')sig=-1;
        c = getchar();
    }
    while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
    x*=sig;
}

void put(long long x)  
{  
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
}
int main(){
    //ios::sync_with_stdio(false);
    get(Q);
    while (Q--){
        get(sig);
        get(v);
        level=getlevel(v);
        mod=(long long)1<<level;
        v-=mod-1;
        if (sig==1){
            get(u);
            u%=mod;
            if (u<0)u+=mod;
            a[level]+=u;
            if (a[level]>=mod)a[level]-=mod;
        }else
        if (sig==2){
            get(u);
            u%=mod;
            if (u<0)u+=mod;
            while (level<60){
                a[level]+=u;
                if (a[level]>=mod)a[level]-=mod;
                mod<<=1;
                u<<=1;
                level++;
            }
        }else{
            (v+=a[level])%=mod;
            if (!v)v=mod;
            while (level>=0){
                u=v-a[level];
                if (u<=0)u+=mod;
                put(u-1+mod);
                putchar(' ');
                v=(v+1)/2;
                level--;
                mod>>=1;
            }
            putchar('\n');
        }
    }
    return 0;
}