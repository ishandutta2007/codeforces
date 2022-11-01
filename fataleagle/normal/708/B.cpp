#include <bits/stdc++.h>

using namespace std;

int aa, ab, ba, bb;

int main()
{
    cin>>aa>>ab>>ba>>bb;
    int a=-1;
    for(int i=1; i<=1000000; i++) if(1LL*i*(i-1)/2==aa)
    {
        a=i;
        break;
    }
    if(a==-1)
        return printf("Impossible\n"), 0;
    if(ab==0 && ba==0 && bb==0)
        return printf("%s\n", string(a, '0').c_str()), 0;
    int b=-1;
    for(int i=1; i<=1000000; i++) if(1LL*i*(i-1)/2==bb)
    {
        b=i;
        break;
    }
    if(b==-1)
        return printf("Impossible\n"), 0;
    if(aa==0 && ab==0 && ba==0)
        return printf("%s\n", string(b, '1').c_str()), 0;
    if(a==-1 || b==-1 || ab+ba!=1LL*a*b)
        return printf("Impossible\n"), 0;
    if(a==0)
    {
        string s(b, '1');
        puts(s.c_str());
        return 0;
    }
    int p=ab/a;
    int q=ba/a;
    int r=ab%a;
    if(ab%a==0 && ba%a==0)
    {
        string s=string(q, '1')+string(a, '0')+string(p, '1');
        puts(s.c_str());
        return 0;
    }
    string s=string(q, '1')+string(r, '0')+"1"+string(a-r, '0')+string(p, '1');
    puts(s.c_str());
    return 0;
}