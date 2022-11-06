#include <cstdio>
typedef long long LL;
#define N 300000 + 5 
#define K 1000
#define Base 233
#define Mod1 1306213
#define Mod2 1301551

int n, type, len, tot, size, Trie[N][26], Num[N], Hash_1[N], Hash_2[N], Pow_1[N], Pow_2[N];
char s[N];

struct HASH
{
	int len, h_1, h_2;
	HASH (int _len = 0, int _h_1 = 0, int _h_2 = 0)
	{
		len = _len, h_1 = _h_1, h_2 = _h_2;
	}
	bool operator == (const HASH a) const
	{
		return len == a.len && h_1 == a.h_1 && h_2 == a.h_2;
	}
}A[N];

inline void Prepare()
{
	Pow_1[0] = Pow_2[0] = 1;
	for (int i = 1; i < N; i ++)
	{
		Pow_1[i] = Pow_1[i - 1] * Base % Mod1;
		Pow_2[i] = Pow_2[i - 1] * Base % Mod2;
	}
}

inline void Get_Hash(int &h_1, int &h_2)
{
	h_1 = h_2 = 0;
	for (int i = 0; i < len; i ++)
	{
		int j = s[i] - 'a' + 5;
		s[i] = '\0';
		h_1 = (h_1 * Base + j) % Mod1;
		h_2 = (h_2 * Base + j) % Mod2;
	}
}

inline void Get_hash()
{
	for (int i = 0; i < len; i ++)
	{
		int j = s[i] - 'a' + 5;
		Hash_1[i + 1] = (Hash_1[i] * Base + j) % Mod1;
		Hash_2[i + 1] = (Hash_2[i] * Base + j) % Mod2;
	}
}

inline bool Check(int pos, HASH x)
{
	if (len - pos < x.len) return 0;
	int h_1 = (Hash_1[pos + x.len] + Mod1 - (1LL * Hash_1[pos] * Pow_1[x.len] % Mod1)) % Mod1;
	int h_2 = (Hash_2[pos + x.len] + Mod2 - (1LL * Hash_2[pos] * Pow_2[x.len] % Mod2)) % Mod2;
	return h_1 == x.h_1 && h_2 == x.h_2;
}

int main()
{
	Prepare();
	scanf("%d", &n);
	while (n --)
	{
		scanf("%d%s", &type, s);
		for (len = 0; s[len] != '\0'; len ++) ;
		if (type <= 2 && len <= K)
		{
			int u = 0;
			for (int i = 0; i < len; i ++)
			{
				int j = s[i] - 'a';
				s[i] = '\0';
				if (!Trie[u][j])
					Trie[u][j] = ++ tot;
				u = Trie[u][j];
			}
			Num[u] += (type == 1 ? 1 : -1);
		}
		else if (type <= 2)
		{
			int h_1, h_2;
			Get_Hash(h_1, h_2);
			HASH x = HASH(len, h_1, h_2);
			if (type == 1) A[++ size] = x;
			else for (int i = 1; i <= size; i ++)
				if (A[i] == x)
				{
					A[i] = A[size --];
					break ;
				}
		}
		else
		{
			LL ans = 0;
			Get_hash();
			for (int i = 0; i < len; i ++)
			{
				for (int j = i, u = 0; j < len; j ++)
				{
					int d = s[j] - 'a';
					if (!Trie[u][d]) break ;
					u = Trie[u][d];
					ans += Num[u];
				}
				for (int j = 1; j <= size; j ++)
					ans += Check(i, A[j]);
			}
			for (int i = 0; i < len; i ++) s[i] = '\0';
			printf("%I64d\n", ans);
			fflush(stdout);
		}
	}
	return 0;
}