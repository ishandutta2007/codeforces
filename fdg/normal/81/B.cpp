#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char mas[1000]={0};
    gets(mas);
    string s(mas);
    for(int i=1;i<s.size();i++)
    {
        if (i>0&&s[i-1]==' '&&s[i]==',')
        {
            s.erase(s.begin()+i-1);
            i--; i--;
        }
    }
    for(int i=0;i<s.size()-1;i++)
    {
        if (i+1<s.size()&&s[i+1]==' '&&s[i]=='.')
        {
            s.erase(s.begin()+i+1);
            i--; i--;
        }
    }
    for(int i=1;i<s.size();i++)
        if (i>0&&s[i-1]==s[i]&&s[i]==' ')
        {
            s.erase(s.begin()+i);
            i--; i--;
        }
    if (s.size()==1&&s[0]==' ')
    {
        cout << endl;
        return 0;
    }
    for(int i=0;i<s.size()-1;i++)
        if (s[i]==',')
        {
            if (s[i+1]!=' ') s.insert(s.begin()+i+1,' ');
            while(i+2<s.size()&&s[i+2]==' ' ) s.erase(s.begin()+i+2);
        }
    for(int i=0;i<s.size();i++)
    {
        if (s[i]=='.')
        {
            if (i==0) i+=2;
            else
            {
                s.insert(s.begin()+i,' ');
                while(i-1>=0&&s[i-1]==' ')
                {
                    s.erase(s.begin()+i-1);
                    i--;
                }
                i+=3;
            }
        }
    }
    for(int i=1;i<s.size();i++)
    {
        if (s[i]==' ')
        {
            int l=i,r=i;
            while(l>0&&s[l-1]==' ') l--;
            while(r<s.size()-1&&s[r+1]==' ') r++;
            if (s[l]>='0'&&s[l]<='9'&&s[r]>='0'&&s[r]<='9')
            {
                if (l+2<=r)
                {
                    s.erase(s.begin()+l+2,s.begin()+r);
                    i=l;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}