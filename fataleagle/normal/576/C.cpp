#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

int N;

struct pt
{
    int x, y, i;
    bool operator< (const pt& other) const
    {
        if(x/1000!=other.x/1000)
            return x/1000<other.x/1000;
        if(x/1000%2==1)
            return y<other.y;
        return y>other.y;
    }
} A[1000000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int a, b;
        scan(a);
        scan(b);
        A[i].x=a;
        A[i].y=b;
        A[i].i=i+1;
    }
    sort(A, A+N);
    for(int i=0; i<N; i++)
    {
        print(A[i].i);
        if(i+1==N)
            putchar('\n');
        else
            putchar(' ');
    }
    return 0;
}