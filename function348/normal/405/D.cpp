#include<iostream>
#include<cstdio>
#include<cstring>
#define ws wss
#define fill(a) memset(a,0,sizeof(a))
using namespace std;
const int N=1000010,inf=1000000;
int a[N],b[N],p[N];
int main()
{
    int n;
    scanf("%d",&n);
    fill(b);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=1;
    }
    int tot=0,cnt=0;
    for (int i=0;i<n;i++)
        if (b[inf+1-a[i]]==0) {p[tot++]=inf+1-a[i];b[inf+1-a[i]]=1;}
        else cnt++;
    cnt/=2;
    for (int i=1;i<=inf&&cnt>0;i++)
        if (b[i]==0&&b[inf+1-i]==0)
        {
            cnt--;
            p[tot++]=i;
            p[tot++]=inf+1-i;
            b[i]=b[inf+1-i]=1;
        }
    cout << tot << endl;
    for (int i=0;i<tot-1;i++) cout << p[i] << ' ';
    cout << p[tot-1] << endl;
}