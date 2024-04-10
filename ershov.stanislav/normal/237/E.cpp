#include <iostream>
#include <cstring>

using namespace std;
#define inf 1 << 30
int ar[128][128], n, ans, N, mark[128], b=1;

int path(int node, int flow) {
    if (node==N-1) return flow;
    mark[node] = b;
    for (int i=0; i<N; i++) if (mark[i]<b&&ar[node][i]) {
        int tmp = path(i, min(flow, ar[node][i]));
        if (tmp) {
        	ar[node][i]-=tmp;
        	ar[i][node]+=tmp;
        	return tmp;
        }
    }
    return 0;
}

int main()
{
    char s[256];
    cin >> s >> n;
    N=n+28;
    int len=strlen(s);
    for (int i=0; i<len; i++) ar[n+1+s[i]-'a'][N-1]++;
    for (int i=0; i<n; i++) {
        cin >> s >> ar[0][i+1];
        len=strlen(s);
        for (int j=0; j<len; j++) ar[i+1][n+1+s[j]-'a']++;
    }
    while(true) {
    	if(!path(0, inf)) break;
    	b++;
    }
    for (int i=0; i<n; i++) for (int j=0; j<26; j++) ans+=(i+1)*ar[n+1+j][i+1];
    for (int i=n+1; i<=n+26; i++) if (ar[i][N-1]) ans=-1;
    cout << ans;
    return 0;
}