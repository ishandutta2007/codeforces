#include <iostream>
#include <map>
#include <vector>
bool correct = true;
std::vector<std::string> cite_vector;
std::map<std::string,std::vector<std::string>> bibitem_map;

void read()
{
	while (true)
	{
		std::string s; std::cin >> s;
		if (s.substr(0, 6) == "\\begin")
			break;
		if (s.substr(0, 5) == "\\cite")
		{
			int end_pos = s.find("}") + 1;
			cite_vector.push_back(s.substr(6, end_pos - 7));
		}
	}
	std::string bibitem;
	std::vector<std::string> description_vector;
	while (true)
	{
		std::string s; std::cin >> s;
		if (s.substr(0, 4) == "\\end")
		{
			bibitem_map[bibitem] = description_vector;
			break;
		}
		if (s.substr(0, 8) == "\\bibitem")
		{
			if (!bibitem.empty())
			{
				bibitem_map[bibitem] = description_vector;
				description_vector.clear();
			}
			int end_pos = s.find("}") + 1;
			bibitem = s.substr(9, end_pos - 10);
			description_vector.push_back(s.substr(end_pos, s.size() - end_pos));
			if (cite_vector[bibitem_map.size()] != bibitem)
				correct = false;
		}
		else 
			description_vector.push_back(s);
	}
}

void write()
{
	std::cout << "\\begin{thebibliography}{99}\n";
	for (std::string s : cite_vector)
	{
		std::cout << "\\bibitem{" << s << "}";
		bool start_flag = false;
		for (std::string t : bibitem_map[s])
		{
			if (start_flag)
				std::cout << " ";
			start_flag = true;
			std::cout << t;
		}
		std::cout << "\n";
	}
	std::cout << "\\end{thebibliography}";
}

int main()
{
	read();
	if (correct)
		std::cout << "Correct\n";
	else 
	{
		std::cout << "Incorrect\n";
		write();
	}
	return 0;
}