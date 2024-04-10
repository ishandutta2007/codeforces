n = gets().to_i
for i in 1..n
	line = gets().split(/(\d+)/)
	if line.length >= 4
		col = line[3].to_i
		for j in 1..100
			break if 26**j >= col
			col -= 26**j
		end
		s = (col-1).to_s(26).rjust(j,'0').tr('0123456789abcdefghijklmnop', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')
		puts s << line[1]
	else
		row = line[1]
		ans = 1 + line[0].tr('ABCDEFGHIJKLMNOPQRSTUVWXYZ', '0123456789abcdefghijklmnop').to_i(26) 
		for j in 1..line[0].length-1
			ans += 26**j
		end
		puts 'R' << row << 'C' << ans.to_s
	end
end