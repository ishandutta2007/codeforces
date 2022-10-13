#include<iostream>
#include<algorithm>
#define fr(a,b,c) for(a=b;a<=c;a++)
using namespace std;

int n,l[7][7],h[7][7],a[7][7],s[7],re=-1;

void inc (int x,int f,int cost);

void att(int x,int y,int f,int cost)
{ 
    if (y>n) 
    {
       if (!f) inc(x+1,s[x+1],cost); 
       return;
    }
    int i;
    fr(i,l[x][y],min(f,h[x][y])) 
    {
        s[y]+=i;
        att(x,y+1,f-i,cost+i*i+(i?a[x][y]:0));
        s[y]-=i;
    }
}

void inc(int x,int f,int cost)
{
    if (x==n) re=max(re,cost); 
    else att(x,x+1,f,cost);     
}

int main()
{
    //freopen("input.in","r",stdin); freopen("output.out","w",stdout);
    int i,j,x,y;
    cin >> n;
    fr(i,1,n*(n-1)>>1)
    {
        cin >> x >> y;              
        cin >> l[x][y] >> h[x][y] >> a[x][y];
    }
    fr(i,0,n*5-5)
    {
      inc(1,i,0);
      if (re>=0) break;
    }
    if (i>n*5-5) cout << "-1 -1" << endl;
    else cout << i << " " << re << endl;  
    //fclose(stdin); fclose(stdout);
    return 0;
}