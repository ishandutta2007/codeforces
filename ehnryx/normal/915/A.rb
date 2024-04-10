#!/usr/bin/ruby
include Math

n, k = readline.split().map(&:to_i)
a = readline().split().map(&:to_i)
ans = 0
a.each do |x|
	if k % x == 0
		ans = [ans, x].max
	end
end
puts k/ans