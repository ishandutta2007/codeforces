#include <bits/stdc++.h>
using namespace std;
const string COLORS = "RGBYW";

int n, num[111], color[111];
string cards[111];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> cards[i];
		num[i] = cards[i][1] - '1';
		color[i] = 0;
		while (COLORS[color[i]] != cards[i][0]) color[i]++;
	}
	
	int ans = 8;
	for (int maskColor = 0; maskColor < 32; maskColor++)
		for (int maskNum = 0; maskNum < 32; maskNum++)
		{
			int known[111] = {0}, colorKnown[111] = {0}, numKnown[111] = {0}, ok = 1;
			//cout << maskColor << ' ' << maskNum << endl;
			for (int i = 0; i < n; i++)
			{
				colorKnown[i] = maskColor >> color[i] & 1 || maskColor + (1 << color[i]) == 31;
				numKnown[i] = maskNum >> num[i] & 1 || maskNum + (1 << num[i]) == 31;
				known[i] = colorKnown[i] && numKnown[i];
			}
					
			while (1)
			{
				int stop = 1;
				int which = -1;
				for (int i = 0; i < n; i++)
					if (!known[i])
						stop = 0, which = i;
				
				if (stop) break;
				
				for (int i = 0; i < n; i++)	
					if (!known[i])
					{
						int hasDifColor = 0;
						for (int j = 0; j < n; j++)
							if (!colorKnown[j] && color[j] != color[i]) hasDifColor = 1;
						if (!hasDifColor) colorKnown[i] = 1;
						int hasDifNum = 0;
						for (int j = 0; j < n; j++)
							if (!numKnown[j] && num[j] != num[i]) hasDifNum = 1;
						if (!hasDifNum) numKnown[i] = 1;
					}						
				
				int found = 0;
				for (int i = 0; i < n; i++)
					if (!known[i])
					{
						if (colorKnown[i])
						{
							int isBad = 0;
							for (int j = 0; j < n; j++)
								if (color[i] == color[j] && num[i] != num[j] && !numKnown[j])
									isBad = 1;
							if (!isBad) numKnown[i] = 1;
						}
						else if (numKnown[i])
						{
							int isBad = 0;
							for (int j = 0; j < n; j++)
								if (num[i] == num[j] && color[i] != color[j] && !colorKnown[j])
									isBad = 1;
							if (!isBad) colorKnown[i] = 1;
						}
						
						known[i] = colorKnown[i] && numKnown[i];
						found |= known[i];
					}
				
				if (!found)
				{
					ok = 0; 
					break;
				}
			}
			
			if (ok) ans = min(ans, __builtin_popcount(maskColor) + __builtin_popcount(maskNum));
		}
	
	cout << ans << endl;
}