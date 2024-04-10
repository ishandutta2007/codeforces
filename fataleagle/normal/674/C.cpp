#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200001];
long long S[200001];
double R[200001];
double T[200001];
double dp[51][200001];

vector<pair<double, double>> st;

double intersectionX(double m1, double b1, double m2, double b2)
{
    return (b2-b1)/(m1-m2);
}

void add_line(double m, double b)
{
    while(st.size()>=2 &&
          intersectionX(st[st.size()-2].first,
                        st[st.size()-2].second,
                        m,
                        b)
                        <=
          intersectionX(st[st.size()-2].first,
                        st[st.size()-2].second,
                        st[st.size()-1].first,
                        st[st.size()-1].second)
          )
        st.pop_back();
    st.push_back(make_pair(m, b));
}

double get_y(double x, int line)
{
    return st[line].first*x+st[line].second;
}

int cur;

double get_min_opt(double x)
{
    int sz=st.size()-1;
    cur=min(cur, sz);
    while(cur<sz && get_y(x, cur+1)<=get_y(x, cur))
        cur++;
    return get_y(x, cur);
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), S[i]=A[i]+S[i-1], R[i]=1.0/A[i]+R[i-1], T[i]=(double)S[i]/A[i]+T[i-1];
    for(int i=1; i<=N; i++)
        dp[1][i]=dp[1][i-1]+(double)S[i]/A[i];
    for(int i=2; i<=K; i++)
    {
        cur=0;
        st.clear();
        for(int j=i-1; j<i; j++)
            add_line(-S[j], dp[i-1][j]+S[j]*R[j]-T[j]);
        for(int j=i; j<=N; j++)
        {
            dp[i][j]=get_min_opt(R[j])+T[j];
            add_line(-S[j], dp[i-1][j]+S[j]*R[j]-T[j]);
        }
    }
    printf("%.6f\n", dp[K][N]);
    return 0;
}