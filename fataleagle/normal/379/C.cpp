#include <iostream>
#include <algorithm>

using namespace std;

bool flag;

struct person
{
    int a, i, r;
    bool operator< (const person& other) const
    {
        if(flag)
            return i<other.i;
        return a<other.a;
    }
} p[300001];

int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>p[i].a;
        p[i].i=i;
    }
    sort(p, p+N);
    int lowbound=0;
    for(int i=0; i<N; i++)
    {
        p[i].r=max(lowbound, p[i].a);
        lowbound=p[i].r+1;
    }
    flag=true;
    sort(p, p+N);
    for(int i=0; i<N; i++)
        cout<<p[i].r<<' ';
    cout<<endl;

    return 0;
}