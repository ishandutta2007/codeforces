#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    char a[n];
    for(int i=0;i<n;i++) a[i]=s.at(i);
    int x=0,y=0,z=0;
    int ax[n];
    int ay[n];
    int az[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0') {ax[x]=i;x++;}
        else if(a[i]=='1') {ay[y]=i;y++;}
        else if(a[i]=='2') {az[z]=i;z++;}
    }
    int x0=x;
    int y0=y;
    int z0=z;
    int ii=0;
    if(x>n/3)
    {
        int i=x0-1;
        if(z<n/3)
        {
            int k=min(x-n/3,n/3-z);
            for(int j=0;j<k;j++)
            {
                a[ax[i]]='2';
                x--;
                z++;
                i--;
            }
        }
        if(x>n/3)
        {
            int k=x-n/3;
            for(int j=0;j<k;j++)
            {
                a[ax[i]]='1';
                y++;
                x--;
                i--;
            }
        }
    }
    else if(x<n/3)
    {
        if(z>n/3)
        {
            int k=min(n/3-x,z-n/3);
            int i=0;
            for(int j=0;j<k;j++)
            {
                a[az[ii]]='0';
                z--;
                x++;
                ii++;
            }
        }
        if(x<n/3)
        {
            int i=0;
            int k=n/3-x;
            for(int j=0;j<k;j++)
            {
                a[ay[i]]='0';
                y--;
                x++;
                i++;
            }
        }
    }
    if(y>n/3)
    {
        int i=y0-1;
        int k=y-n/3;
        for(int j=0;j<k;j++)
        {
            a[ay[i]]='2';
            y--;
            z++;
            i--;
        }
    }
    else if(y<n/3)
    {
        int i=0;
        int k=n/3-y;
        for(int j=0;j<k;j++)
        {
            a[az[ii]]='1';
            z--;
            y++;
            ii++;
        }
    }
    for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}