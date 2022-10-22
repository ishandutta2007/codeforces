#include<iostream>
#include<cstdio>
using namespace std;
int T,x,y;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main(){T=get();while(T--)x=get(),y=get(),x<y?swap(x,y),0:0,put(x-y>1?y*2+1+2*(x-y-1):x+y),putchar('\n');return 0;}