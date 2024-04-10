#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long n,m,a[10001][801]={0},ii,jj,d[100001]={0},f[100001]={0},i1=0,i2=0,q;
char s[100001][11];
void swa(long &a,long &b)
{
    long temp=a;
    a=b;
    b=temp;
}
void sw(char a[],char b[])
{
    char t[20];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);
}
void quicksort(long *arr, long left, long right,char s[][11],long f[]){
    long mi = (left+right)/2;
    long i = left;
    long j = right;
    long pivot = arr[mi];

    while(left<j || i<right)
    {
        while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<=j){
            swa(arr[i],arr[j]);
            swa(f[i],f[j]);
            sw(s[i],s[j]);
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(arr, left, j,s,f);
            if(i<right)
                quicksort(arr,i,right,s,f);
            return;
        }
    }
}
int main()
{
   cin>>n>>m;
   for(ii=1;ii<=n;++ii)
   {cin>>s[ii]>>d[ii]>>f[ii];
    a[d[ii]][f[ii]]++;}
    f[0]=-1;
    quicksort(d,1,n,s,f);
  //  for(i=1;i<=n;++i)
      //  cout<<s[i]<<"  "<<d[i]<<"  "<<f[i]<<endl;
      q=1;
    for(ii=1;ii<=m;++ii)
    {i1=0;i2=0;
        for(jj=q;jj<=n;++jj)
        {
            if(d[jj]==ii)
            {
                if(f[jj]>=f[i2]) {i1=i2;i2=jj;}
                if(f[jj]<f[i2] && f[jj]>f[i1]) i1=jj;
            }
            else {q=jj;break;}
        }
     if(a[ii][f[i2]]+a[ii][f[i1]]==2 || a[ii][f[i2]]==2) cout<<s[i2]<<" "<<s[i1];
     else cout<<'?';
     cout<<endl;
    }
  return 0;
}