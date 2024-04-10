#include <bits/stdc++.h>

using namespace std;

int N, Q;
int bit[1048577];

void add(int x, int v)
{
    for(x++; x<=1048576; x+=x&-x)
        bit[x]+=v;
}

int query(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++)
        add(i, 1);
    int a, b, c;
    int start=0, len=N;
    bool rev=false;
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        if(a==1)
        {
            if(rev)
            {
                if(b<=len-b)
                {
                    for(int j=0; j<b; j++)
                        add(start+len-b-j-1, query(start+len-b+j)-query(start+len-b+j-1));
                    len-=b;
                }
                else
                {
                    rev^=1;
                    for(int j=0; j<len-b; j++)
                        add(start+(len-b)*2-j-1, query(start+j)-query(start+j-1));
                    start+=len-b;
                    len-=len-b;
                }
            }
            else
            {
                if(b<=len-b)
                {
                    for(int j=0; j<b; j++)
                        add(start+b*2-j-1, query(start+j)-query(start+j-1));
                    start+=b;
                    len-=b;
                }
                else
                {
                    rev^=1;
                    for(int j=0; j<len-b; j++)
                        add(start+b-j-1, query(start+b+j)-query(start+b+j-1));
                    len-=len-b;
                }
            }
        }
        else
        {
            scanf("%d", &c);
            if(rev)
                printf("%d\n", query(start+len-b-1)-query(start+len-c-1));
            else
                printf("%d\n", query(start+c-1)-query(start+b-1));
        }
    }
    return 0;
}