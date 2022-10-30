#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _;
bool _ssign;

using namespace std;

int N, K;
pair<int, int> ev[2000000];

int main()
{
    scan(N); scan(K);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scan(a); scan(b);
        ev[i*2]=make_pair(a*2, 1);
        ev[i*2+1]=make_pair(b*2+1, -1);
    }
    sort(ev, ev+2*N);
    vector<int> ans;
    int n=0;
    for(int i=0, j; i<2*N; i=j)
    {
        for(j=i; j<2*N && ev[i].first==ev[j].first; j++)
            n+=ev[j].second;
        if(n>=K && ans.size()%2==0)
            ans.push_back(ev[i].first);
        if(n<K && ans.size()%2==1)
            ans.push_back(ev[i].first-1);
    }
    printf("%d\n", ans.size()/2);
    for(int i=0; i<(int)ans.size()/2; i++)
        printf("%d %d\n", ans[i*2]/2, ans[i*2+1]/2);
    return 0;
}