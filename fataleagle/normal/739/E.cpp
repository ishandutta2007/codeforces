#include <cstdio>
#include <iostream>
#include <nmmintrin.h>

#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

using namespace std;

int N, A, B;
int PA[2000];
int PB[2000];
int PAB[2000];
int ALIGN(16) dp[2002][2004];

int main()
{
#ifdef FATALEAGLE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &A, &B);
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d.%d", &a, &b);
        PA[i]=(a*1000+b)*1000;
    }
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d.%d", &a, &b);
        PB[i]=(a*1000+b)*1000;
    }
    for(int i=0; i<N; i++)
        PAB[i]=PA[i]+PB[i]-(PA[i]/1000)*(PB[i]/1000);
    for(int i=0; i<N; i++)
    {
        int X=min(A, i);
        int Y=min(B, i);
        int a=PA[i], b=PB[i], ab=PAB[i];
        int ALIGN(16) a4[4]={a, a, a, a};
        int ALIGN(16) b4[4]={b, b, b, b};
        int ALIGN(16) ab4[4]={ab, ab, ab, ab};
        __m128i va4=_mm_load_si128((__m128i*)a4);
        __m128i vb4=_mm_load_si128((__m128i*)b4);
        __m128i vab4=_mm_load_si128((__m128i*)ab4);
        for(int j=X; j>=0; j--)
        {
            int k;
            for(k=Y; k>=0 && k%4!=3; k--)
            {
                dp[j+1][k]=max(dp[j+1][k], dp[j][k]+a);
                dp[j][k+1]=max(dp[j][k+1], dp[j][k]+b);
                dp[j+1][k+1]=max(dp[j+1][k+1], dp[j][k]+ab);
            }
            if(k>=0)
            {
                k-=3;
                for(; k>=0; k-=4)
                {
                    __m128i k4=_mm_load_si128((__m128i*)(dp[j]+k));
                    __m128i jk4=_mm_load_si128((__m128i*)(dp[j+1]+k));
                    __m128i k4pa=_mm_add_epi32(k4, va4);
                    __m128i k4pb=_mm_slli_si128(_mm_add_epi32(k4, vb4), 4);
                    __m128i k4pab=_mm_slli_si128(_mm_add_epi32(k4, vab4), 4);
                    __m128i r0=_mm_blendv_epi8(k4pb, k4, _mm_cmpgt_epi32(k4, k4pb));
                    __m128i r1=_mm_blendv_epi8(k4pa, jk4, _mm_cmpgt_epi32(jk4, k4pa));
                    __m128i r2=_mm_blendv_epi8(k4pab, r1, _mm_cmpgt_epi32(r1, k4pab));
                    if(dp[j][k+3]+b>dp[j][k+4])
                        dp[j][k+4]=dp[j][k+3]+b;
                    if(dp[j][k+3]+ab>dp[j+1][k+4])
                        dp[j+1][k+4]=dp[j][k+3]+ab;
                    _mm_store_si128((__m128i*)(dp[j]+k), r0);
                    _mm_store_si128((__m128i*)(dp[j+1]+k), r2);
                }
            }
        }
    }
    printf("%d.%06d\n", dp[A][B]/1000000, dp[A][B]%1000000);
    return 0;
}