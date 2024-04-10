#include <bits/stdc++.h>

using namespace std;

int N;
char S[200100];
char T[200100];
int A[256];
int B[256];

int main()
{
    scanf("%s%s", S, T);
    N=max(strlen(S), strlen(T));
    for(int i=0; i<N; i++)
        A[S[i]]++, B[T[i]]++;
    int yay=0;
    for(int i='a'; i<='z'; i++) {
        int tmp=min(A[i], B[i]);
        yay+=tmp, A[i]-=tmp, B[i]-=tmp;
    }
    for(int i='A'; i<='Z'; i++) {
        int tmp=min(A[i], B[i]);
        yay+=tmp, A[i]-=tmp, B[i]-=tmp;
    }
    int whoops=0;
    for(int i='a'; i<='z'; i++) {
        int tmp=min(A[i], B[i-'a'+'A']);
        whoops+=tmp, A[i]-=tmp, B[i-'a'+'A']-=tmp;
    }
    for(int i='a'; i<='z'; i++) {
        int tmp=min(B[i], A[i-'a'+'A']);
        whoops+=tmp, B[i]-=tmp, A[i-'a'+'A']-=tmp;
    }
    printf("%d %d\n", yay, whoops);
    return 0;
}